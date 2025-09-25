HRESULT CreatePrintControl(
  [in]                IWICImagingFactory                    *wicFactory,
  [in]                IPrintDocumentPackageTarget           *documentTarget,
  [in, ref, optional] const D2D1_PRINT_CONTROL_PROPERTIES & printControlProperties,
  [out]               ID2D1PrintControl                     **printControl
);