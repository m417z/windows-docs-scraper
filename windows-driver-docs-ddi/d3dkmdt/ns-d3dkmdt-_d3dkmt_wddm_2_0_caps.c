typedef struct _D3DKMT_WDDM_2_0_CAPS {
  union {
    struct {
      UINT Support64BitAtomics : 1;
      UINT GpuMmuSupported : 1;
      UINT IoMmuSupported : 1;
      UINT FlipOverwriteSupported : 1;
      UINT SupportContextlessPresent : 1;
      UINT SupportSurpriseRemoval : 1;
#if ...
      UINT Reserved : 26;
#elif
      UINT Reserved : 27;
#else
      UINT Reserved : 29;
#endif
    };
    UINT Value;
  };
} D3DKMT_WDDM_2_0_CAPS;