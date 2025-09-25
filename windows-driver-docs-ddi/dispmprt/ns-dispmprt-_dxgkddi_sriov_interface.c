typedef struct _DXGKDDI_SRIOV_INTERFACE {
  IN USHORT                                    Size;
  IN USHORT                                    Version;
  OUT PVOID                                    Context;
  OUT PINTERFACE_REFERENCE                     InterfaceReference;
  OUT PINTERFACE_DEREFERENCE                   InterfaceDereference;
  OUT PDXGKDDI_READVIRTUALFUNCTIONCONFIG       DxgkDdiReadVirtualFunctionConfig;
  OUT PDXGKDDI_WRITEVIRTUALFUNCTIONCONFIG      DxgkDdiWriteVirtualFunctionConfig;
  OUT PDXGKDDI_READVIRTUALFUNCTIONCONFIGBLOCK  DxgkDdiReadVirtualFunctionConfigBlock;
  OUT PDXGKDDI_WRITEVIRTUALFUNCTIONCONFIGBLOCK DxgkDdiWriteVirtualFunctionConfigBlock;
  OUT PDXGKDDI_QUERYPROBEDBARS                 DxgkDdiQueryProbedBars;
  OUT PDXGKDDI_GETVENDORANDDEVICE              DxgkDdiGetVendorAndDevice;
  OUT PDXGKDDI_GETDEVICELOCATION               DxgkDdiGetDeviceLocation;
  OUT PDXGKDDI_RESETVIRTUALFUNCTION            DxgkDdiResetVirtualFunction;
  OUT PDXGKDDI_SETVIRTUALFUNCTIONPOWERSTATE    DxgkDdiSetVirtualFunctionPowerState;
  OUT PDXGKDDI_GETRESOURCEFORBAR               DxgkDdiGetResourceForBar;
  OUT PDXGKDDI_QUERYVIRTUALFUNCTIONLUID        DxgkDdiQueryVirtualFunctionLuid;
} DXGKDDI_SRIOV_INTERFACE, *PDXGKDDI_SRIOV_INTERFACE;