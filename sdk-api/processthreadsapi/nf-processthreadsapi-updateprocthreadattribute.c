BOOL UpdateProcThreadAttribute(
  [in, out]       LPPROC_THREAD_ATTRIBUTE_LIST lpAttributeList,
  [in]            DWORD                        dwFlags,
  [in]            DWORD_PTR                    Attribute,
  [in]            PVOID                        lpValue,
  [in]            SIZE_T                       cbSize,
  [out, optional] PVOID                        lpPreviousValue,
  [in, optional]  PSIZE_T                      lpReturnSize
);