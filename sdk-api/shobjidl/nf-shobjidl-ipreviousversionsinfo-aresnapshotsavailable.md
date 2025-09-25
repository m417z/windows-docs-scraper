# IPreviousVersionsInfo::AreSnapshotsAvailable

## Description

Queries for the availability of a Windows Server 2003 volume image recorded by the system at an earlier time.

## Parameters

### `pszPath` [in]

Type: **LPCWSTR**

A null-terminated Unicode string containing the fully qualified path to a file or folder on the volume in question.

**Note** Only paths to files and folders stored on a Windows Server 2003 volume are currently supported.

### `fOkToBeSlow` [in]

Type: **BOOL**

A boolean value specifying whether a server should be contacted to determine the availability of stored volume images. For more details, see the Remarks section.

#### TRUE

Contact the server if the results are not already cached.

#### FALSE

Do not contact the server. Use cached results instead.

### `pfAvailable` [out]

Type: **BOOL***

A pointer to a boolean variable containing the result. This value is valid only if the method call succeeds; otherwise, it is undefined.

#### TRUE

At least one stored image of the volume where the file or folder named in *pszPath* resides is available.

#### FALSE

No volume images are stored.

## Return value

Type: **HRESULT**

Returns standard error values, including, but not limited to, the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_PENDING** | *fOkToBeSlow* is **FALSE** and the result is not currently cached. |

## Remarks

If **IPreviousVersionsInfo::AreSnapshotsAvailable** is called on a file or folder, the result does not indicate that rollback information is available for that specific file or folder, merely that a snapshot of the entire volume is available. This result is cached and subsequent calls inquiring about anything stored on that same volume access the cached results—with little performance overhead—instead of recontacting the server.

Once the server's response is cached in memory, subsequent calls do not contact the server even if *fOkToBeSlow* is **TRUE**. If *fOkToBeSlow* is **FALSE** and the server's response is not already cached from a previous call, the method returns E_PENDING. In that case, set *fOkToBeSlow* to **TRUE** and call **IPreviousVersionsInfo::AreSnapshotsAvailable** again to contact the server.

For better performance, a UI thread calling this method should always set *fOkToBeSlow* to **FALSE**. If the method returns E_PENDING, follow these steps.

* Create another instance of [IPreviousVersionsInfo](https://learn.microsoft.com/windows/desktop/api/shobjidl/nn-shobjidl-ipreviousversionsinfo) on a background thread.
* Call **IPreviousVersionsInfo::AreSnapshotsAvailable** with *fOkToBeSlow* set to **TRUE**.
* Signal the original UI thread to call **IPreviousVersionsInfo::AreSnapshotsAvailable** again. The results are then pulled from the cache.