KSDDKAPI BOOLEAN KsFastPropertyHandler(
  PFILE_OBJECT         FileObject,
  PKSPROPERTY          Property,
  ULONG                PropertyLength,
  PVOID                Data,
  ULONG                DataLength,
  PIO_STATUS_BLOCK     IoStatus,
  ULONG                PropertySetsCount,
  const KSPROPERTY_SET *PropertySet
);