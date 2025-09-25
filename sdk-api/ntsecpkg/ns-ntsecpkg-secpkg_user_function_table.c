typedef struct _SECPKG_USER_FUNCTION_TABLE {
  SpInstanceInitFn              *InstanceInit;
  SpInitUserModeContextFn       *InitUserModeContext;
  SpMakeSignatureFn             *MakeSignature;
  SpVerifySignatureFn           *VerifySignature;
  SpSealMessageFn               *SealMessage;
  SpUnsealMessageFn             *UnsealMessage;
  SpGetContextTokenFn           *GetContextToken;
  SpQueryContextAttributesFn    *QueryContextAttributes;
  SpCompleteAuthTokenFn         *CompleteAuthToken;
  SpDeleteContextFn             *DeleteUserModeContext;
  SpFormatCredentialsFn         *FormatCredentials;
  SpMarshallSupplementalCredsFn *MarshallSupplementalCreds;
  SpExportSecurityContextFn     *ExportContext;
  SpImportSecurityContextFn     *ImportContext;
  SpMarshalAttributeDataFn      *MarshalAttributeData;
} SECPKG_USER_FUNCTION_TABLE, *PSECPKG_USER_FUNCTION_TABLE;