NTSTATUS WdfIoResourceListCreate(
  [in]           WDFIORESREQLIST        RequirementsList,
  [in, optional] PWDF_OBJECT_ATTRIBUTES Attributes,
  [out]          WDFIORESLIST           *ResourceList
);