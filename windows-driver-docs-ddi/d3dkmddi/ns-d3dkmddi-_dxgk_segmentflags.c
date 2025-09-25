typedef struct _DXGK_SEGMENTFLAGS {
  union {
    struct {
      UINT Aperture : 1;
      UINT Agp : 1;
      UINT CpuVisible : 1;
      UINT UseBanking : 1;
      UINT CacheCoherent : 1;
      UINT PitchAlignment : 1;
      UINT PopulatedFromSystemMemory : 1;
      UINT PreservedDuringStandby : 1;
      UINT PreservedDuringHibernate : 1;
      UINT PartiallyPreservedDuringHibernate : 1;
      UINT DirectFlip : 1;
      UINT Use64KBPages : 1;
      UINT ReservedSysMem : 1;
      UINT SupportsCpuHostAperture : 1;
      UINT SupportsCachedCpuHostAperture : 1;
      UINT ApplicationTarget : 1;
      UINT VprSupported : 1;
      UINT VprPreservedDuringStandby : 1;
      UINT EncryptedPagingSupported : 1;
      UINT LocalBudgetGroup : 1;
      UINT NonLocalBudgetGroup : 1;
      UINT PopulatedByReservedDDRByFirmware : 1;
#if ...
      UINT Reserved : 10;
#elif
      UINT Reserved : 11;
#elif
      UINT Reserved : 21;
#else
      UINT Reserved : 22;
#endif
    };
    UINT Value;
  };
} DXGK_SEGMENTFLAGS;