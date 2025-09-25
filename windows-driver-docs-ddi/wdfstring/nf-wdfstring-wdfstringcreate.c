NTSTATUS WdfStringCreate(
  [in, optional] PCUNICODE_STRING       UnicodeString,
  [in, optional] PWDF_OBJECT_ATTRIBUTES StringAttributes,
  [out]          WDFSTRING              *String
);