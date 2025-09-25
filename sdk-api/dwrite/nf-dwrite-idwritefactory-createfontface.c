HRESULT CreateFontFace(
        DWRITE_FONT_FACE_TYPE   fontFaceType,
        UINT32                  numberOfFiles,
  [in]  IDWriteFontFile         * const *fontFiles,
        UINT32                  faceIndex,
        DWRITE_FONT_SIMULATIONS fontFaceSimulationFlags,
  [out] IDWriteFontFace         **fontFace
);