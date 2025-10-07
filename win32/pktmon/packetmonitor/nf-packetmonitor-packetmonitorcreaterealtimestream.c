HRESULT
WINAPI
PacketMonitorCreateRealtimeStream(
    _In_ PACKETMONITOR_HANDLE handle,
    _In_ PACKETMONITOR_REALTIME_STREAM_CONFIGURATION const* configuration,
    _Out_ PACKETMONITOR_REALTIME_STREAM* realtimeStream
);