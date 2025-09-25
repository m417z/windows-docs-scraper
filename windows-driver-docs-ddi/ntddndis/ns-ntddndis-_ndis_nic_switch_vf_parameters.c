typedef struct _NDIS_NIC_SWITCH_VF_PARAMETERS {
  NDIS_OBJECT_HEADER     Header;
  ULONG                  Flags;
  NDIS_NIC_SWITCH_ID     SwitchId;
  NDIS_VM_NAME           VMName;
  NDIS_VM_FRIENDLYNAME   VMFriendlyName;
  NDIS_SWITCH_NIC_NAME   NicName;
  USHORT                 MacAddressLength;
  UCHAR                  PermanentMacAddress[NDIS_MAX_PHYS_ADDRESS_LENGTH];
  UCHAR                  CurrentMacAddress[NDIS_MAX_PHYS_ADDRESS_LENGTH];
  NDIS_SRIOV_FUNCTION_ID VFId;
  NDIS_VF_RID            RequestorId;
} NDIS_NIC_SWITCH_VF_PARAMETERS, *PNDIS_NIC_SWITCH_VF_PARAMETERS;