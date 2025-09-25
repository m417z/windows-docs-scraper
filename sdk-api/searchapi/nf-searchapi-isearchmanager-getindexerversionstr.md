# ISearchManager::GetIndexerVersionStr

## Description

Retrieves the version of the current indexer as a single string.

## Parameters

### `ppszVersionString` [out]

Type: **LPWSTR***

Receives the version of the current indexer.

##### 65 on Windows XP/Windows Server 2003

02.06.5000.5378

##### 66 on Windows XP/Windows Server 2003

02.06.6000.5414

##### 0 on Windows XP/Windows Server 2003

03.00.5824.280

##### 01 on Windows XP/Windows Server 2003

03.01.6000.72

#### Windows Search on Windows Vista RTM/Windows Server RTM

03.00.6000.16386

#### Windows Search on Windows Vista SP1/Windows Server 2008

03.00.6001.18000

##### 0 Preview on all platforms

04.00.6001.381

##### 0 on all platforms

04.00.6001.16503

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Check out the [ReindexMatchingUrls code sample](https://learn.microsoft.com/windows/win32/search/-search-sample-reindexmatchingurls) to see ways to specify which files to re-index and how set it up.