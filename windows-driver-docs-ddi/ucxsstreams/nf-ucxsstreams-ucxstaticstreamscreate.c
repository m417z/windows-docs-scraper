NTSTATUS UcxStaticStreamsCreate(
  [in]           UCXENDPOINT            Endpoint,
                 PUCXSSTREAMS_INIT      *StaticStreamsInit,
  [in, optional] PWDF_OBJECT_ATTRIBUTES Attributes,
                 UCXSSTREAMS            *StaticStreams
);