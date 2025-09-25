NTSTATUS BdaCreateFilterFactoryEx(
  [in]            PKSDEVICE                 pKSDevice,
  [in]            const KSFILTER_DESCRIPTOR *pFilterDescriptor,
  [in]            const BDA_FILTER_TEMPLATE *pBdaFilterTemplate,
  [out, optional] PKSFILTERFACTORY          *ppKSFilterFactory
);