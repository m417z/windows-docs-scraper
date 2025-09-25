# IInkDisp::Load

## Description

Populates a new [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object with known binary data.

## Parameters

### `Data` [in]

The stream that contains the ink data.

For more information about the VARIANT structure, see [Using the COM Library](https://learn.microsoft.com/windows/desktop/tablet/using-the-com-library).

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | VARIANT was not of correct type (byte array). |
| **E_OUTOFMEMORY** | Cannot allocate memory for Stream. |
| **E_UNEXPECTED** | Unexpected parameter or property type. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |

## Remarks

You can load ink only into a new, empty [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object - one that hasn't collected any strokes or doesn't have any attached properties. If you try to load ink into an **InkDisp** object that has collected strokes or attached properties, even if the strokes or properties have been deleted from the **InkDisp** object, an exception is thrown. This occurs because of how stroke IDs are assigned. A stroke is assigned a unique ID, and this ID is not reused, even if the stroke has been deleted from an Ink object. This means that, if an **InkDisp** object contained a stroke with an ID of 1 and you deleted the stroke and loaded another **InkDisp** object into this **InkDisp** object, stroke IDs would start at 2. This would be confusing and therefore is not allowed.

**Note** If you do attempt to load ink into an [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object that is not empty, all data in the **InkDisp** object, including any custom strokes or extended properties, is lost when you call **Load**.

The [Save](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkdisp-save) method allows you to persist the ink in an [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object in Graphics Interchange Format (GIF) format, which consists of an array of byte data (the tla_gif persistence format is specified in the [InkPersistenceFormat](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkpersistenceformat) enumeration type). After you have the array of byte data, you can load the array of byte data into another **InkDisp** object. This means that you can load GIF-compatible byte array data into another **InkDisp** object in the same way as if you had called the **Save** method and received a byte array that was not in GIF format.

**Note** You cannot create an image, persist that image as a byte array, and then load that byte array into another [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object. This is because, after you load byte array data as a GIF, Tablet PC cannot control the format of that data. So, after you persist the image into a byte array again, you cannot call **Load** on that data.

## See also

[IInkDisp](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkdisp)

[InkDisp Class](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class)

[Save Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkdisp-save)