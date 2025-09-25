NTSTATUS AcxCircuitTemplateCreate(
  [in]  WDFDRIVER                    Driver,
  [in]  PWDF_OBJECT_ATTRIBUTES       Attributes,
  [in]  PACX_CIRCUIT_TEMPLATE_CONFIG Config,
  [out] ACXCIRCUITTEMPLATE           *Template
);