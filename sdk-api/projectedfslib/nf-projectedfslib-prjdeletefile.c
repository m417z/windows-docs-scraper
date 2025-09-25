HRESULT PrjDeleteFile(
  [in]            PRJ_NAMESPACE_VIRTUALIZATION_CONTEXT namespaceVirtualizationContext,
  [in]            PCWSTR                               destinationFileName,
  [in, optional]  PRJ_UPDATE_TYPES                     updateFlags,
  [out, optional] PRJ_UPDATE_FAILURE_CAUSES            *failureReason
);