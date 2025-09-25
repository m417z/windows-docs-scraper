WMIDPREQUEST Wmidprequest;

ULONG Wmidprequest(
  [in] WMIDPREQUESTCODE RequestCode,
       PVOID RequestContext,
       ULONG *BufferSize,
  [in] PVOID Buffer
)
{...}