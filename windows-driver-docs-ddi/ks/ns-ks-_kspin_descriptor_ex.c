typedef struct _KSPIN_DESCRIPTOR_EX {
  const KSPIN_DISPATCH         *Dispatch;
  const KSAUTOMATION_TABLE     *AutomationTable;
  KSPIN_DESCRIPTOR             PinDescriptor;
  ULONG                        Flags;
  ULONG                        InstancesPossible;
  ULONG                        InstancesNecessary;
  const KSALLOCATOR_FRAMING_EX *AllocatorFraming;
  PFNKSINTERSECTHANDLEREX      IntersectHandler;
} KSPIN_DESCRIPTOR_EX, *PKSPIN_DESCRIPTOR_EX;