typedef struct {
  ULONG                   PropertyId;
  union {
    PFNKSHANDLER GetPropertyHandler;
    BOOLEAN      GetSupported;
  };
  ULONG                   MinProperty;
  ULONG                   MinData;
  union {
    PFNKSHANDLER SetPropertyHandler;
    BOOLEAN      SetSupported;
  };
  const KSPROPERTY_VALUES *Values;
  ULONG                   RelationsCount;
  const KSPROPERTY        *Relations;
  PFNKSHANDLER            SupportHandler;
  ULONG                   SerializedSize;
} KSPROPERTY_ITEM, *PKSPROPERTY_ITEM;