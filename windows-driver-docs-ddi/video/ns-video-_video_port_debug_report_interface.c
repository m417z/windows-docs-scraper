typedef struct _VIDEO_PORT_DEBUG_REPORT_INTERFACE
{
    IN USHORT                  Size;
    IN USHORT                  Version;
    OUT PVOID                  Context;
    OUT PINTERFACE_REFERENCE   InterfaceReference;
    OUT PINTERFACE_DEREFERENCE InterfaceDereference;

    OUT
    PVIDEO_DEBUG_REPORT
    (*DbgReportCreate)(
        IN PVOID HwDeviceExtension,
        IN ULONG ulCode,
        IN ULONG_PTR ulpArg1,
        IN ULONG_PTR ulpArg2,
        IN ULONG_PTR ulpArg3,
        IN ULONG_PTR ulpArg4
        );

    OUT
    BOOLEAN
    (*DbgReportSecondaryData)(
        IN OUT PVIDEO_DEBUG_REPORT pReport,
        IN PVOID pvData,
        IN ULONG ulDataSize
        );

    OUT
    VOID
    (*DbgReportComplete)(
        IN OUT PVIDEO_DEBUG_REPORT pReport
        );
} VIDEO_PORT_DEBUG_REPORT_INTERFACE, *PVIDEO_PORT_DEBUG_REPORT_INTERFACE;