typedef struct _KSFILTER_DESCRIPTOR {
  const KSFILTER_DISPATCH     *Dispatch;
  const KSAUTOMATION_TABLE    *AutomationTable;
  ULONG                       Version;
  ULONG                       Flags;
  const GUID                  *ReferenceGuid;
  ULONG                       PinDescriptorsCount;
  ULONG                       PinDescriptorSize;
  const KSPIN_DESCRIPTOR_EX   *PinDescriptors;
  ULONG                       CategoriesCount;
  const GUID                  *Categories;
  ULONG                       NodeDescriptorsCount;
  ULONG                       NodeDescriptorSize;
  const KSNODE_DESCRIPTOR     *NodeDescriptors;
  ULONG                       ConnectionsCount;
  const KSTOPOLOGY_CONNECTION *Connections;
  const KSCOMPONENTID         *ComponentId;
} KSFILTER_DESCRIPTOR, *PKSFILTER_DESCRIPTOR;