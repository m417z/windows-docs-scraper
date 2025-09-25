# ResUtilFindDependentDiskResourceDriveLetter function

## Description

Retrieves the drive letter associated with a
[Physical Disk](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/physical-disk)
[dependency](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-dependencies) of a
[resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources). The **PRESUTIL_FIND_DEPENDENT_DISK_RESOURCE_DRIVE_LETTER** type defines a pointer to this function.

## Parameters

### `hCluster` [in]

Cluster handle.

### `hResource` [in]

Handle to the resource to query for dependencies.

### `pszDriveLetter` [out]

Buffer in which to store the drive letter.

### `pcchDriveLetter` [in, out]

On input, specifies the size of the *pszDriveLetter* buffer as a count of
**WCHAR**s. On output, specifies the size of the resulting data as a count of
**WCHAR**s that includes the terminating **NULL**.

## Return value

If the operations succeeds, the function returns **ERROR_SUCCESS** (0).

If the operation fails, the function returns a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes). The following are possible error
codes.

| Return code | Description |
| --- | --- |
| **ERROR_NO_MORE_ITEMS** | No Physical Disk dependency was found in the specified resource's list of dependencies. |
| **ERROR_RESOURCE_NOT_PRESENT** | No drive letter could be returned. |
| **ERROR_MORE_DATA** | The buffer passed in was too small. The *pcchDriveLetter* parameter specifies the required size. |

## Remarks

Do not call this function from a [resource DLL](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-dlls). It will
cause a deadlock. You should have your resource extension call this function and write the results out as a
private property that your resource DLL can then read.

If the resource identified by hResource depends on more than one Physical Disk resource,
**ResUtilFindDependentDiskResourceDriveLetter**
returns the drive letter of the first Physical Disk dependency that is enumerated for the resource.

#### Examples

The following example takes a resource name as a command line argument and displays the drive letter
associated with the resource's Physical Disk dependency (if any). This example uses the
[ClusDocEx.h](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusdocex-h) header file defined in the Failover Cluster
documentation.

```cpp
//////////////////////////////////////////////////////////////////////

#include "ClusDocEx.h"

int main( int argc, char argv[] )
 {
  HCLUSTER  hCluster     = NULL;
  HRESOURCE hRes         = NULL;
  DWORD     dw;
  DWORD     cchResDrive  = ClusDocEx_DEFAULT_CCH;
  DWORD     cchResName   = ClusDocEx_DEFAULT_CCH;
  WCHAR     *pszResDrive = new WCHAR[cchResDrive];
  WCHAR     *pszResName  = new WCHAR[cchResName];

  dw = ClusDocEx_ConvertArg( argv[1], pszResName, cchResName );

  if( dw == ERROR_SUCCESS )
   {
    hCluster = ClusDocEx_OpenLocalClusterWithName();
    if( hCluster != NULL )
     {
      hRes = OpenClusterResource( hCluster, pszResName );
      if( hRes != NULL )
       {
        dw = ResUtilFindDependentDiskResourceDriveLetter( hCluster,
                                                          hRes,
                                                          pszResDrive,
                                                          &cchResDrive );

        if( dw == ERROR_MORE_DATA )
         {
          delete [] pszResDrive;
          pszResDrive = new WCHAR[cchResDrive];
          dw = ResUtilFindDependentDiskResourceDriveLetter( hCluster,
                                                            hRes,
                                                            pszResDrive,
                                                            &cchResDrive );
         }

        switch( dw )
         {
          case ERROR_SUCCESS:
            wprintf( L"%ls depends on drive %ls.\n", pszResName, pszResDrive );
            break;

          case ERROR_NO_MORE_ITEMS:
          case ERROR_RESOURCE_NOT_PRESENT:
            wprintf( L"No Physical Disk dependency found for %ls.\n", pszResName );
            break;

          default:
            ClusDocEx_DebugPrint( L"Could not obtain drive information", dw );
            break;
         }
        CloseClusterResource( hRes );
       }
      else // if hRes == NULL
       {
        ClusDocEx_DebugPrint( L"Could not open a resource handle", GetLastError() );
       }
      CloseCluster( hCluster );
     }
    else // if hCluster == NULL
     {
      ClusDocEx_DebugPrint( L"Could not open a cluster handle", GetLastError() );
     }

   }
  delete [] pszResName;
  delete [] pszResDrive;
  return 0;
 }

```

If the resource identified by *hResource* refers to a mount point disk, there may or
may not be a drive letter associated with the disk resource. If the mount point disk has no associated drive
letter, the value returned by
**ResUtilFindDependentDiskResourceDriveLetter**
will be in the format of *DiskXPartitionY*, which is valid data but cannot be passed
directly to file system APIs such as [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea).

The following example takes the output string from
**ResUtilFindDependentDiskResourceDriveLetter**
and transforms it to Win32 format. The output string from this function can be passed to
[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea). If the function fails, the return value is
**NULL**; call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) to
get extended error info. If the function succeeds the user has to free the buffer returned using
[LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree).

```cpp
#define UNICODE 1
#define _UNICODE 1
#pragma comment(lib, "ResUtils.lib")

#include <windows.h>
#include <stdlib.h>
#include <ResApi.h>
#include <strsafe.h>

#define IS_DRIVELETTER(x) ((iswalpha((x)[0])) && ((x)[1] == L':'))
#define IS_NTPATH(x) ((wcsstr((x), L"Disk") != NULL) && (wcsstr((x), L"Partition") != NULL))
#define GLOBALROOT_DISK_FORMAT L"\\\\\?\\GLOBALROOT\\Device\\Harddisk%u\\Partition%u"

LPWSTR ConvertNtDiskPathToW32DiskPath( LPCWSTR InputString )
 {
  LPWSTR outputString=NULL;
  DWORD status=ERROR_INVALID_PARAMETER;
  DWORD len;
  DWORD diskNum, partNum;

  if ((InputString == NULL) || (InputString[0] == 0))
   {
    goto Error_exit;
   }

  // Find out the required buffer size.
  len = 0;
  if (IS_DRIVELETTER(InputString))
   {
    len = wcslen(InputString) + 4;
   }
  else if (IS_NTPATH(InputString))
   {
    len = wcslen(GLOBALROOT_DISK_FORMAT) + 16;
   }
  else
   {
    //Malformed string.
    goto Error_exit;
   }

  if ((outputString = (LPWSTR)LocalAlloc(LPTR, len * sizeof(WCHAR))) == NULL)
   {
    status = GetLastError();
    goto Error_exit;
   }

  if (IS_DRIVELETTER(InputString))
   {
    StringCchCopyW(outputString, len, InputString);
   }
  else
   {
    //Has to be NT path format.
    swscanf_s(InputString, L"Disk%uPartition%u", &diskNum, &partNum);
    StringCchPrintfW(outputString, len, GLOBALROOT_DISK_FORMAT, diskNum, partNum);
   }

  status = ERROR_SUCCESS;

Error_exit:

  if (status != ERROR_SUCCESS)
   {
    if (outputString)
     {
      LocalFree(outputString);
     }
    SetLastError(status);
    return NULL;
   }

  return outputString;
 }

```

## See also

[ResUtilGetResourceDependency](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilgetresourcedependency)

[ResUtilGetResourceDependencyByClass](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilgetresourcedependencybyclass)

[ResUtilGetResourceDependencyByName](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilgetresourcedependencybyname)

[ResUtilGetResourceDependentIPAddressProps](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilgetresourcedependentipaddressprops)

[ResUtilGetResourceNameDependency](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilgetresourcenamedependency)

[Resource Utility Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-utility-functions)