# ITfCandidateList::GetCandidateNum

## Description

Obtains the number of candidate string objects in the candidate list.

## Parameters

### `pnCnt` [out]

Pointer to a **ULONG** value that receives the number of candidate string objects in the candidate list.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | *pnCnt* is invalid. |