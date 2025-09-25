typedef struct {
  const GUID                *Set;
  ULONG                     PropertiesCount;
  const KSPROPERTY_ITEM     *PropertyItem;
  ULONG                     FastIoCount;
  const KSFASTPROPERTY_ITEM *FastIoTable;
} KSPROPERTY_SET, *PKSPROPERTY_SET;