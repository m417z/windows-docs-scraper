typedef struct _RADIUS_ATTRIBUTE_ARRAY {
  DWORD                  cbSize;
  DWORD((_RADIUS_ATTRIBUTE_ARRAY *This, const RADIUS_ATTRIBUTE *pAttr)                 * )Add;
  const RADIUS_ATTRIBUTE  )(const _RADIUS_ATTRIBUTE_ARRAY *This,DWORD dwIndex) *(*AttributeAt;
  DWORD()(const _RADIUS_ATTRIBUTE_ARRAY *This)                 * GetSize;
  DWORD((_RADIUS_ATTRIBUTE_ARRAY *This,DWORD dwIndex, const RADIUS_ATTRIBUTE *pAttr)                 * )InsertAt;
  DWORD()(_RADIUS_ATTRIBUTE_ARRAY *This,DWORD dwIndex)                 * RemoveAt;
  DWORD((_RADIUS_ATTRIBUTE_ARRAY *This,DWORD dwIndex, const RADIUS_ATTRIBUTE *pAttr)                 * )SetAt;
} RADIUS_ATTRIBUTE_ARRAY, *PRADIUS_ATTRIBUTE_ARRAY;