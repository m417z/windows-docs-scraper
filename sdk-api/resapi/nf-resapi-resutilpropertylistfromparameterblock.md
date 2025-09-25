# ResUtilPropertyListFromParameterBlock function

## Description

Constructs a
[property list](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/property-lists) from a
[property table](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/property-tables) and a
[parameter block](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/parameter-blocks).

## Parameters

### `pPropertyTable` [in]

Pointer to a property table describing the properties that will be included in the resulting property list.

### `pOutPropertyList` [out, optional]

Pointer to an output buffer that receives the property list.

### `pcbOutPropertyListSize` [in, out]

Pointer to the size of the output buffer in bytes.

### `pInParams` [in]

Pointer to the parameter block in which the property values are stored.

### `pcbBytesReturned` [out]

If the function returns **ERROR_SUCCESS**, *pcbBytesReturned* points to the actual byte size of the property list pointed to by *pOutPropertyList*. If the function does not return **ERROR_SUCCESS**, *pcbBytesReturned* points to a value of zero.

### `pcbRequired` [out]

If the function returns **ERROR_MORE_DATA**, *pcbRequired* points to the byte size required to contain the property list. If the function does not return **ERROR_MORE_DATA**, *pcbBytesReturned* points to a value of zero.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails, the function returns a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes). The following are possible error
codes.

| Return code | Description |
| --- | --- |
| **ERROR_MORE_DATA** | The output buffer is too small to contain the resulting property list. |
| **ERROR_BAD_ARGUMENTS** | One or more of the input parameters were invalid. |
| **ERROR_NOT_ENOUGH_MEMORY** | There was an error allocating memory. |

## Remarks

In this function, the property table determines the order in which the properties appear in the property list, as well as the name and format of each property. The function reads the property table to determine the name and format of each property.

The parameter block provides the property values.

#### Examples

The following example defines three properties (Protocol, PortNumber, and ConnectionName). It uses the
**ResUtilPropertyListFromParameterBlock** function to create a property list. This
example uses the [ClusDocEx.h](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusdocex-h) header file defined in the
Failover Cluster documentation.

```cpp
//////////////////////////////////////////////////////////////////////

//  Be sure to create the following file before you compile.
//  For a code listing, see "ClusDocEx.h".
    #include "ClusDocEx.h"

//////////////////////////////////////////////////////////////////////

//  This example defines three fictional properties:
//      Protocol (DWORD)
//      PortNumber (DWORD)
//      ConnectionName (PWSTR)
//  These properties are not associated with any cluster object.
//  They are used only to demonstrate the
//  ResUtilPropertyListFromParameterBlock function.

//  Protocol property constants
    #define PROP_NAME__PROTOCOL       L"Protocol"
    typedef enum PROTOCOLS{
        PROTOCOL_NONE = 0,
        PROTOCOL_BOTH = 1,
        PROTOCOL_TCP  = 2,
        PROTOCOL_UDP  = 3
    };
    #define PROP_MIN__PROTOCOL       (PROTOCOL_NONE)
    #define PROP_MAX__PROTOCOL       (PROTOCOL_UDP)
    #define PROP_DEFAULT__PROTOCOL   (PROTOCOL_BOTH)

//  PortNumber property
    #define PROP_NAME__PORTNUMBER     L"PortNumber"
    #define PROP_MIN__PORTNUMBER      (0)
    #define PROP_MAX__PORTNUMBER      (65536)
    #define PROP_DEFAULT__PORTNUMBER  (80)

//  ConnectionName property
    #define PROP_NAME__CONNECTIONNAME L"ConnectionName"

//  Parameter block
    typedef struct _PARAMBLOCK{
        DWORD dwProtocol;
        DWORD dwPortNumber;
        PWSTR pszConnectionName;
    } PARAMBLOCK;

//  Property table
    RESUTIL_PROPERTY_ITEM
    pPropTable[] =
    {
        {   PROP_NAME__PROTOCOL,
            NULL,
            CLUSPROP_FORMAT_DWORD,
            PROP_DEFAULT__PROTOCOL,
            PROP_MIN__PROTOCOL,
            PROP_MAX__PROTOCOL,
            RESUTIL_PROPITEM_REQUIRED,
            FIELD_OFFSET( _PARAMBLOCK, dwProtocol )        },

        {   PROP_NAME__PORTNUMBER,
            NULL,
            CLUSPROP_FORMAT_DWORD,
            PROP_DEFAULT__PORTNUMBER,
            PROP_MIN__PORTNUMBER,
            PROP_MAX__PORTNUMBER,
            RESUTIL_PROPITEM_REQUIRED,
            FIELD_OFFSET( _PARAMBLOCK, dwPortNumber )      },

        {   PROP_NAME__CONNECTIONNAME,
            NULL,
            CLUSPROP_FORMAT_SZ,
                0, 0, 0, 0,
            FIELD_OFFSET( _PARAMBLOCK, pszConnectionName ) },

        { 0 }
    };

    int main()
    {
        DWORD nResult    = ERROR_SUCCESS,
              cbBufSize  = 1024,
              cbReturned = 0,
              cbRequired = 0;

        PVOID pPropList = LocalAlloc( LPTR, cbBufSize );

    //  Values for the property list
        PARAMBLOCK NewParams = { PROTOCOL_TCP, 21, L"FTP" };

        nResult = ResUtilPropertyListFromParameterBlock(
                      pPropTable,
                      pPropList,
                      &cbBufSize,
                      (LPBYTE) &NewParams,
                      &cbReturned,
                      &cbRequired );

        if( nResult == ERROR_MORE_DATA )
        {
            LocalFree( pPropList );

            cbBufSize = cbRequired;

            pPropList = LocalAlloc( LPTR, cbBufSize );

            nResult = ResUtilPropertyListFromParameterBlock(
                          pPropTable,
                          pPropList,
                          &cbBufSize,
                          (PBYTE) &NewParams,
                          &cbReturned,
                          &cbRequired );
        }

        ClusDocEx_DebugPrint( L"Results:", nResult );

        if( nResult == ERROR_SUCCESS )
            ClusDocEx_ShowBuffer( pPropList, cbReturned );

        LocalFree( pPropList );

        return (int)( nResult != ERROR_SUCCESS );
    }

```

## See also

[RESUTIL_PROPERTY_ITEM](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/ns-resapi-resutil_property_item)