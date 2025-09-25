typedef struct _KSFILTER {
  const KSFILTER_DESCRIPTOR *Descriptor;
  KSOBJECT_BAG              Bag;
  PVOID                     Context;
} KSFILTER, *PKSFILTER;