FORCEINLINE
VOID
VHF_CONFIG_INIT(
    _Out_
        PVHF_CONFIG     Config,
#ifdef _KERNEL_MODE
    _In_
        PDEVICE_OBJECT  DeviceObject,
#else
    _In_
        HANDLE          FileHandle,
#endif
    _In_
        USHORT          ReportDescriptorLength,
    _In_reads_bytes_(ReportDescriptorLength)
        PUCHAR          ReportDescriptor    
    )