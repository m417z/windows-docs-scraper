# ITfPreservedKeyNotifySink::OnUpdated

## Description

Called when a key is preserved, unpreserved, or when a preserved key description changes.

## Parameters

### `pprekey` [in]

Pointer to a [TF_PRESERVEDKEY](https://learn.microsoft.com/windows/desktop/api/msctf/ns-msctf-tf_preservedkey) structure that contains data about the key.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To determine if the key is unpreserved, call [ITfKeystrokeMgr::IsPreservedKey](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfkeystrokemgr-ispreservedkey), passing *pprekey*. If the key is not found, it is unpreserved. If the key is found, it is either preserved or the description has changed. Unless you keep track of the current key description and compare the previous description with the current description in response to this notification, there is no way to determine if this notification is in response to a key preserved or the description changed.

## See also

[ITfKeystrokeMgr::PreserveKey](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfkeystrokemgr-preservekey)

[ITfKeystrokeMgr::SetPreservedKeyDescription](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfkeystrokemgr-setpreservedkeydescription)

[ITfKeystrokeMgr::UnpreserveKey](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfkeystrokemgr-unpreservekey)

[ITfPreservedKeyNotifySink](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfpreservedkeynotifysink)

[TF_PRESERVEDKEY](https://learn.microsoft.com/windows/desktop/api/msctf/ns-msctf-tf_preservedkey)