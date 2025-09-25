HRESULT ClipboardCopyWithRectangle(
  [in]           IInkRectangle       *Rectangle,
  [in, optional] InkClipboardFormats ClipboardFormats,
  [in, optional] InkClipboardModes   ClipboardModes,
  [out, retval]  IDataObject         **DataObject
);