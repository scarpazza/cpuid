// Descriptions of the feature bits and fields returned by CPUID
//

# pragma once

#include <sys/types.h>
namespace cpuid {

  struct leaf7_subleaf2 {
    struct eax_features {
      uint32_t unused;
    };
    struct ebx_features {
      uint32_t unused;
    };

    struct ecx_features {
      uint32_t unused;
    };

    struct edx_features {
      uint32_t psfd              :1; // 0 Fast Store Forwarding Predictor disable supported. (SPEC_CTRL (MSR 48h) bit 7)
      uint32_t ipred_ctrl        :1; // 1 IPRED_DIS controls supported. (SPEC_CTRL bits 3 and 4) IPRED_DIS prevents instructions at an indirect branch target from speculatively executing until the branch target address is resolved.
      uint32_t rrsba_ctrl        :1; // 2 RRSBA behavior disable supported. (SPEC_CTRL bits 5 and 6)
      uint32_t ddpd_u            :1; // 3 Data Dependent Prefetcher disable supported. (SPEC_CTRL bit 8)
      uint32_t bhi_ctrl          :1; // 4 BHI_DIS_S behavior enable supported. (SPEC_CTRL bit 10) - BHI_DIS_S prevents predicted targets of indirect branches executed in ring0/1/2 from being selected based on branch history from branches executed in ring 3.
      uint32_t mcdt_no           :1; // 5 If set, the processor does not exhibit MXCSR configuration dependent timing.
      uint32_t uc_lock_dis       :1; // 6 UC-lock disable feature supported.
      uint32_t monitor_mitg_no	 :1; // 7 If set, indicates that the MONITOR/UMONITOR instructions are not affected by performance/power issues caused by the instructions exceeding the capacity of an internal monitor tracking table.

    };

    static_assert( sizeof(eax_features) == sizeof(uint32_t) );
    static_assert( sizeof(ebx_features) == sizeof(uint32_t) );
    static_assert( sizeof(ecx_features) == sizeof(uint32_t) );
    static_assert( sizeof(edx_features) == sizeof(uint32_t) );

  }; // struct leaf7_subleaf2
}; // namespace cpuid
