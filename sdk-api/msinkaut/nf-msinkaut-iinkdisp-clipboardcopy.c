HRESULT ClipboardCopy(
  [in, optional] IInkStrokes         *strokes,
  [in, optional] InkClipboardFormats ClipboardFormats,
  [in, optional] InkClipboardModes   ClipboardModes,
  [out, retval]  IDataObject         **DataObject
);