# IWMDMStorageControl3::Insert3

## Description

The **Insert3** method puts content into/next to the storage. This method extends **IWMDMStorageControl2::Insert2** by allowing the application to explicitly specify the metadata and type of the object being sent.

## Parameters

### `fuMode` [in]

Processing mode used for the **Insert3** operation. The following table lists the processing modes that can be specified in the *fuMode* parameter. You must specify exactly one of the first two modes, exactly one of the STORAGECONTROL modes, and exactly one of the CONTENT modes. If both WMDM_MODE_BLOCK and WMDM_MODE_THREAD are specified, block mode is used. Specifying the WMDM_FILE_ATTR* flags in this function is more efficient than calling this function first, then setting these attributes on the file after it has been created or sent.

| Combinations | Mode | Description |
| --- | --- | --- |
| Exactly one of: | WMDM_MODE_BLOCK | The operation is performed using block mode processing. The call will not return until the operation is finished. |
| - | WMDM_MODE_THREAD | The operation is performed using thread mode processing. The call will return immediately, and the operation is performed in a background thread. |
| Optional | WMDM_MODE_QUERY | A test is performed to determine whether the insert operation could succeed, but the insert will not be performed. |
| Exactly one of: | WMDM_STORAGECONTROL_INSERTBEFORE | The object is inserted before the target object. |
| - | WMDM_STORAGECONTROL_INSERTAFTER | The object is inserted after the target object. |
| - | WMDM_STORAGECONTROL_INSERTINTO | The object is inserted into the current object. This will only work if the current object is a folder. |
| Optional | WMDM_FILE_CREATE_OVERWRITE | The object will replace the target object. |
| Exactly one of: | WMDM_CONTENT_FILE | The content being inserted is a file. |
| - | WMDM_CONTENT_FOLDER | The content being inserted is a folder. This will not transfer the contents of the folder. |
| Optional | WMDM_CONTENT_OPERATIONINTERFACE | The application is passing in an **IWMDMOperation** interface to control data transfer. |
| Zero or more of: | WMDM_FILE_ATTR_READONLY | The storage should be set to read-only on the device. |
| - | WMDM_FILE_ATTR_HIDDEN | The storage should be set to hidden on the device. |
| - | WMDM_FILE_ATTR_SYSTEM | The storage should be set to system on the device. |
| Optional | WMDM_MODE_PROGRESS | The insertion is in progress. |
| Optional one of: | WMDM_MODE_TRANSFER_PROTECTED | The insertion is in protected transfer mode. |
| - | WMDM_MODE_TRANSFER_UNPROTECTED | The insertion is in unprotected transfer mode. |

### `fuType` [in]

One of the following types, specifying the current storage.

| Value | Description |
| --- | --- |
| WMDM_FILE_ATTR_FILE | The current storage is a file. |
| WMDM_FILE_ATTR_FOLDER | The current storage is a folder. |

### `pwszFileSource` [in]

Pointer to a wide-character, **null**-terminated string indicating where to find the content for the insert operation. This parameter must be **NULL** if WMDM_CONTENT_OPERATIONINTERFACE is specified in *fuMode*. This parameter can be **NULL** if a playlist or album is being created.

### `pwszFileDest` [in]

Optional name of file on the device. If not specified and the application passes an **IWMDMOperation** pointer to *pOperation*, Windows Media Device Manager will request a destination name by calling [IWMDMOperation::GetObjectName](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmoperation-getobjectname). If not specified and the application does not use *pOperation*, the original file name and extension are used (without the path).

### `pOperation` [in]

Optional pointer to an [IWMDMOperation](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmoperation) interface, to control the transfer of content to a media device. If specified, *fuMode* must include the WMDM_CONTENT_OPERATIONINTERFACE flag. This parameter must be **NULL** if WMDM_CONTENT_FILE or WMDM_CONTENT_FOLDER is specified in *fuMode*.

### `pProgress` [in]

Optional pointer to an [IWMDMProgress](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmprogress) interface to report action progress back to the application. This parameter can be **NULL**.

### `pMetaData` [in]

Optional pointer to a metadata object. Create a new metadata object by calling [IWMDMStorage3::CreateEmptyMetadataObject](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmstorage3-createemptymetadataobject). This parameter allows an application to specify metadata (including format) to set on the device during object creation on the device, which is more efficient than setting metadata afterward. You must set the file format (specified by g_wszWMDMFormatCode). If you do not specify the format code of a file when using this method, an MTP device will not show the file as present in its user interface, and non-MTP devices will behave unpredictably.

### `pUnknown` [in]

Optional **IUnknown** pointer of any custom COM object to be passed to the secure content provider. This makes it possible to pass custom information to a secure content provider if the application has sufficient information about the secure content provider.

### `ppNewObject` [out]

Pointer to an **IWMDMStorage** interface that will contain the new content. The caller must release this interface when finished with it.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

Although you can set metadata on a storage after sending it to the device, it is more efficient to set this information in the *pMetaData* parameter of this method. Doing so provides additional information to the device to enable it to transfer and handle the file appropriately (for example, by storing it in the correct place) or display useful information (such as a user-written description of a picture).

To set properties for a Windows Portable Devices (WPD) device, an application would create an **IPortableDeviceValues** object and set each property into this collection. Then, the application would serialize the collection to a binary large object (BLOB). Once the data is serialized, the application would add it to the **IWMDMMetaData** referenced by the *pMetadata* argument using the g_wszWPDPassthroughPropertyValues metadata constant.

If the WMDM_MODE_THREAD flag is specified, you should obtain completion status by calling either [IWMDMProgress2::End2](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmprogress2-end2) or [IWMDMProgress3::End3](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmprogress3-end3). These methods will ensure that the operation is complete and will also return an HRESULT with success or failure information.

If an application uses WMDM_MODE_THREAD and passes a non-**null***pProgress* parameter, the application must ensure that the object to which *pProgress* belongs is not destroyed until the read operation completes, because Windows Media Device Manager will send progress notifications to this object. This object can be destroyed only after it receives an end notification. Failure to do this will result in access violations.

When creating a playlist or other reference object, the object being "inserted" actually contains no data but is simply stored on the device as a group of metadata references to other objects (such as music files). Creating such an "abstract" object on the playlist is described in [Creating a Playlist on the Device](https://learn.microsoft.com/windows/desktop/WMDM/creating-a-playlist-on-the-device).

#### Examples

The following C++ function sends a file to a device. As part of the transfer, it must add metadata to the storage to specify the new storage type.

```cpp

HRESULT mySendFile(LPCWSTR pwszFileName, IWMDMStorage* pStorage, IWMDMOperation* pOperation)
{
   HRESULT hr = S_OK;

   // A dummy loop to handle unrecoverable errors. When we hit an error we
   // can't handle or don't like, we just use a 'break' statement.
   // The custom BREAK_HR macro checks for failed HRESULT values and does this.
   do
   {
      if (pwszFileName == NULL || pStorage == NULL)
      {
         BREAK_HR(E_POINTER,"","Bad pointer passed in.");
         return E_POINTER;
      }

      // Make sure the destination is a folder.
      DWORD attributes = 0;
      _WAVEFORMATEX format;
      hr = pStorage->GetAttributes(&attributes, &format);
      if (!(attributes | WMDM_FILE_ATTR_FOLDER))
      {
         BREAK_HR(E_FAIL, "", "Storage submitted to mySendFile is not a folder.");
         return E_FAIL;
      }

      // Transcode the file
      hr = myTranscodeMethod(pwszFileName);
      BREAK_HR(hr, "Couldn't transcode the file in mySendFile.", "Transcoded the file in mySendFile.");
      //
      // Let's set some metadata in the storage.
      //
      CComPtr<IWMDMStorage3> pStorage3;
      hr = pStorage->QueryInterface(__uuidof(IWMDMStorage3), (void**)(&pStorage3));
      BREAK_HR(hr, "Got an IWMDMStorage3 interface in mySendFile.","Couldn't get an IWMDMStorage3 in mySendFile.");

      // First create the IWMDMMetaData interface.
      IWMDMMetaData* pMetadata;
      hr = pStorage3->CreateEmptyMetadataObject(&pMetadata);
      BREAK_HR(hr,"Created an IWMDMMetaData interface in mySendFile.","Couldn't create an IWMDMMetaData interface in mySendFile.");

      //
      // Set the file format.
      //
      WMDM_FORMATCODE fileFormat = myGetWMDM_FORMATCODE(pwszFileName);
      hr = pMetadata->AddItem(WMDM_TYPE_DWORD, g_wszWMDMFormatCode, (BYTE*)&fileFormat, sizeof(WMDM_TYPE_DWORD));

      //
      // Get the proper interface and transfer the file.
      //
      CComPtr<IWMDMStorageControl3> pStgCtl3;
      CComPtr<IWMDMStorage> pNewStorage;
      hr = pStorage->QueryInterface(__uuidof(IWMDMStorageControl3),(void**)(&pStgCtl3));

      // Get the simple file name to use for the destination file.
      wstring destFile = pwszFileName;
      destFile = destFile.substr(destFile.find_last_of(L"\\") + 1);

      // Get a progress indicator.
      CComQIPtr<IWMDMProgress> pProgress(this);

      // Set the flags for the operation.
      UINT flags = WMDM_MODE_BLOCK | // Synchronous call.
         WMDM_STORAGECONTROL_INSERTINTO | // Insert it into the destination folder.
         WMDM_CONTENT_FILE | // We're inserting a file.
         WMDM_FILE_CREATE_OVERWRITE; // Overwrite existing files.
      if (pOperation != NULL)
         flags |= WMDM_CONTENT_OPERATIONINTERFACE;

      // Send the file and metadata.
      hr = pStgCtl3->Insert3(
         flags,
         WMDM_FILE_ATTR_FOLDER, // The current storage is a folder.
         const_cast<WCHAR*>(pwszFileName), // Source file.
         NULL, // Destination file name.
         pOperation, // Null to allow Windows Media Device Manager to read
                     // the file; non-null to present raw data bytes to
                     // Windows Media Device Manager.
         pProgress, // Interface to send simple progress notifications.
         pMetadata, // IWMDMMetaData interface previously created and filled.
         NULL,
         &pNewStorage);
      if (FAILED(hr))
         m_pLogger->LogDword(WMDM_LOG_SEV_ERROR, NULL, "Error calling Insert3 in mySendFile: %lX", hr);
      BREAK_HR(hr, "Wrote a file to the device in mySendFile", "Couldn't write to the device in mySendFile.");

   } while (FALSE); // End of dummy loop

   return hr;
}

```

## See also

[Creating a Playlist on the Device](https://learn.microsoft.com/windows/desktop/WMDM/creating-a-playlist-on-the-device)

[IWMDMDevice::GetStatus](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmdevice-getstatus)

[IWMDMMetaData Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmmetadata)

[IWMDMOperation Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmoperation)

[IWMDMProgress Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmprogress)

[IWMDMStorage Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmstorage)

[IWMDMStorageControl2::Insert2](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmstoragecontrol2-insert2)

[IWMDMStorageControl3 Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmstoragecontrol3)

[Writing Files to the Device](https://learn.microsoft.com/windows/desktop/WMDM/writing-files-to-the-device)