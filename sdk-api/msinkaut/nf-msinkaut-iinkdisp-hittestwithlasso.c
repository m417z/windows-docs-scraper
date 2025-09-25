HRESULT HitTestWithLasso(
  [in]                VARIANT     Points,
  [in]                float       IntersectPercent,
  [in, out, optional] VARIANT     *LassoPoints,
  [out, retval]       IInkStrokes **Strokes
);