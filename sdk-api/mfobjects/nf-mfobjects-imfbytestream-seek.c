HRESULT Seek(
  [in]  MFBYTESTREAM_SEEK_ORIGIN SeekOrigin,
  [in]  LONGLONG                 llSeekOffset,
  [in]  DWORD                    dwSeekFlags,
  [out] QWORD                    *pqwCurrentPosition
);