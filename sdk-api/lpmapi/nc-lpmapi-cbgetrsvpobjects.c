CBGETRSVPOBJECTS Cbgetrsvpobjects;

ULONG * Cbgetrsvpobjects(
  [in] LPM_HANDLE LpmHandle,
  [in] RHANDLE RequestHandle,
  [in] int LpmError,
  [in] int RsvpObjectsCount,
  [in] RsvpObjHdr **ppRsvpObjects
)
{...}