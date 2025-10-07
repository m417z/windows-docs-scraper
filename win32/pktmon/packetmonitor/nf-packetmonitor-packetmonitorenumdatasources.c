HRESULT
WINAPI
PacketMonitorEnumDataSources(
    _In_ PACKETMONITOR_HANDLE handle,
    _In_ PACKETMONITOR_DATA_SOURCE_KIND sourceKind,
    _In_ BOOLEAN showHidden,
    _In_ SIZE_T bufferCapacity,
    _Out_ SIZE_T* bytesNeeded,
    _Out_writes_bytes_opt_(bufferCapacity) PACKETMONITOR_DATA_SOURCE_LIST* dataSourceList
    );