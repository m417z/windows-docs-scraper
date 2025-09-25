NTSTATUS AcxCompositeTemplateAssignCircuits(
  [in]                               ACXCOMPOSITETEMPLATE CompositeTemplate,
  [in, reads(CircuitTemplatesCount)] ACXCIRCUITTEMPLATE   *CircuitTemplates,
  [in]                               ULONG                CircuitTemplatesCount
);