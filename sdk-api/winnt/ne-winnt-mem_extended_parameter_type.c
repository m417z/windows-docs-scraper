typedef enum MEM_EXTENDED_PARAMETER_TYPE {
  MemExtendedParameterInvalidType = 0,
  MemExtendedParameterAddressRequirements,
  MemExtendedParameterNumaNode,
  MemExtendedParameterPartitionHandle,
  MemExtendedParameterUserPhysicalHandle,
  MemExtendedParameterAttributeFlags,
  MemExtendedParameterImageMachine,
  MemExtendedParameterMax
}  *PMEM_EXTENDED_PARAMETER_TYPE;