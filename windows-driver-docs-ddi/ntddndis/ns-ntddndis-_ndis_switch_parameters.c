typedef struct _NDIS_SWITCH_PARAMETERS {
  NDIS_OBJECT_HEADER       Header;
  ULONG                    Flags;
  NDIS_SWITCH_NAME         SwitchName;
  NDIS_SWITCH_FRIENDLYNAME SwitchFriendlyName;
  UINT32                   NumSwitchPorts;
  BOOLEAN                  IsActive;
} NDIS_SWITCH_PARAMETERS, *PNDIS_SWITCH_PARAMETERS;