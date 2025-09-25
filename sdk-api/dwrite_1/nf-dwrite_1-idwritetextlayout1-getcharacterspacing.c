HRESULT GetCharacterSpacing(
                  UINT32            currentPosition,
  [out]           FLOAT             *leadingSpacing,
  [out]           FLOAT             *trailingSpacing,
  [out]           FLOAT             *minimumAdvanceWidth,
  [out, optional] DWRITE_TEXT_RANGE *textRange
);