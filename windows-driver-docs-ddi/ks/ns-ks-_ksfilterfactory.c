typedef struct _KSFILTERFACTORY {
  const KSFILTER_DESCRIPTOR *FilterDescriptor;
  KSOBJECT_BAG              Bag;
  PVOID                     Context;
} KSFILTERFACTORY, *PKSFILTERFACTORY;