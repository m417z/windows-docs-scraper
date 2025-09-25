typedef struct _VHF_CONFIG {

    ULONG                               Size;

    PVOID                               VhfClientContext;

    ULONG                               OperationContextSize;

#ifdef _KERNEL_MODE
    PDEVICE_OBJECT                      DeviceObject;
#else
    HANDLE                              FileHandle;
#endif

    USHORT                              VendorID;
    USHORT                              ProductID;
    USHORT                              VersionNumber;

    GUID                                ContainerID;

    USHORT                              InstanceIDLength;
    _Field_size_bytes_full_(InstanceIDLength)   
    PWSTR                               InstanceID;

    USHORT                              ReportDescriptorLength;
    _Field_size_full_(ReportDescriptorLength)
    PUCHAR                              ReportDescriptor;

    PEVT_VHF_READY_FOR_NEXT_READ_REPORT EvtVhfReadyForNextReadReport;
    PEVT_VHF_ASYNC_OPERATION            EvtVhfAsyncOperationGetFeature;
    PEVT_VHF_ASYNC_OPERATION            EvtVhfAsyncOperationSetFeature;
    PEVT_VHF_ASYNC_OPERATION            EvtVhfAsyncOperationWriteReport;
    PEVT_VHF_ASYNC_OPERATION            EvtVhfAsyncOperationGetInputReport;
    PEVT_VHF_CLEANUP                    EvtVhfCleanup;

    USHORT                              HardwareIDsLength;
    _Field_size_bytes_full_(HardwareIDsLength)
    PWSTR                               HardwareIDs;

} VHF_CONFIG, *PVHF_CONFIG;