PFNKSPINSETDATAFORMAT Pfnkspinsetdataformat;

NTSTATUS Pfnkspinsetdataformat(
  [in]           PKSPIN Pin,
  [in, optional] PKSDATAFORMAT OldFormat,
  [in, optional] PKSMULTIPLE_ITEM OldAttributeList,
  [in]           const KSDATARANGE *DataRange,
  [in, optional] const KSATTRIBUTE_LIST *AttributeRange
)
{...}