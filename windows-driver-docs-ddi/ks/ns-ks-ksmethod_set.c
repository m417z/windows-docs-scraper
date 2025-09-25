typedef struct {
  const GUID              *Set;
  ULONG                   MethodsCount;
  const KSMETHOD_ITEM     *MethodItem;
  ULONG                   FastIoCount;
  const KSFASTMETHOD_ITEM *FastIoTable;
} KSMETHOD_SET, *PKSMETHOD_SET;