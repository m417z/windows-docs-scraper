LSA_AP_INITIALIZE_PACKAGE LsaApInitializePackage;

NTSTATUS LsaApInitializePackage(
  [in]           ULONG AuthenticationPackageId,
  [in]           PLSA_DISPATCH_TABLE LsaDispatchTable,
  [in, optional] PLSA_STRING Database,
  [in, optional] PLSA_STRING Confidentiality,
  [out]          PLSA_STRING *AuthenticationPackageName
)
{...}