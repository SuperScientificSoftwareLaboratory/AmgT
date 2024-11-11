/******************************************************************************
 * Copyright (c) 1998 Lawrence Livermore National Security, LLC and other
 * HYPRE Project Developers. See the top-level COPYRIGHT file for details.
 *
 * SPDX-License-Identifier: (Apache-2.0 OR MIT)
 ******************************************************************************/

/******************************************************************************
 *
 * Header info for the Maxwell solver
 *
 *****************************************************************************/

#ifndef hypre_MAXWELL_HEADER
#define hypre_MAXWELL_HEADER

/*--------------------------------------------------------------------------
 * hypre_MaxwellData:
 *--------------------------------------------------------------------------*/

typedef struct
{
   MPI_Comm                comm;

   HYPRE_Real              tol;
   HYPRE_Int               max_iter;
   HYPRE_Int               rel_change;
   HYPRE_Int               zero_guess;
   HYPRE_Int               ndim;

   HYPRE_Int               num_pre_relax;  /* number of pre relaxation sweeps */
   HYPRE_Int               num_post_relax; /* number of post relaxation sweeps */

   HYPRE_Int               constant_coef;

   hypre_Index            *rfactor;

   hypre_SStructGrid     **egrid_l;

   HYPRE_IJMatrix          Aen;
   hypre_ParCSRMatrix    **Aen_l;

   /* these will be extracted from the amg_data structure. Note that there is no grid
      underlying these matrices and vectors if they are generated by the amg_setup.
      So, will be stored as Parcsr_matrices and Par_vectors. */
   hypre_SStructMatrix    *Ann;
   hypre_SStructVector    *bn;
   hypre_SStructVector    *xn;

   void                   *amg_vdata;
   hypre_ParCSRMatrix    **Ann_l;
   hypre_SStructStencil  **Ann_stencils;
   hypre_ParCSRMatrix    **Pn_l;
   hypre_ParCSRMatrix    **RnT_l;
   hypre_ParVector       **bn_l;
   hypre_ParVector       **xn_l;
   hypre_ParVector       **resn_l;
   hypre_ParVector       **en_l;
   hypre_ParVector       **nVtemp_l;
   hypre_ParVector       **nVtemp2_l;
   HYPRE_Int             **nCF_marker_l;
   HYPRE_Real             *nrelax_weight;
   HYPRE_Real             *nomega;
   HYPRE_Int               nrelax_type;
   HYPRE_Int               node_numlevels;

   hypre_ParCSRMatrix     *Tgrad;
   hypre_ParCSRMatrix     *T_transpose;

   /* edge data structure. These will have grids. */
   HYPRE_Int               edge_maxlevels;
   HYPRE_Int               edge_numlevels;
   hypre_ParCSRMatrix    **Aee_l;
   hypre_ParVector       **be_l;
   hypre_ParVector       **xe_l;
   hypre_ParVector       **rese_l;
   hypre_ParVector       **ee_l;
   hypre_ParVector       **eVtemp_l;
   hypre_ParVector       **eVtemp2_l;
   HYPRE_Int             **eCF_marker_l;
   HYPRE_Real             *erelax_weight;
   HYPRE_Real             *eomega;
   HYPRE_Int               erelax_type;

   /* edge data structure. These will have no grid. */
   hypre_IJMatrix        **Pe_l;
   hypre_IJMatrix        **ReT_l;
   HYPRE_Int             **BdryRanks_l;
   HYPRE_Int              *BdryRanksCnts_l;

   /* edge-node data structure. These will have grids. */
   HYPRE_Int               en_numlevels;

   /* log info (always logged) */
   HYPRE_Int               num_iterations;
   HYPRE_Int               time_index;

   /* additional log info (logged when `logging' > 0) */
   HYPRE_Int               print_level;
   HYPRE_Int               logging;
   HYPRE_Real             *norms;
   HYPRE_Real             *rel_norms;

} hypre_MaxwellData;

#endif