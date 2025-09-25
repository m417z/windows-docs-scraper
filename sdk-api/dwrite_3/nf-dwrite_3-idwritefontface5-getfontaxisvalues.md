## Description

Retrieves the list of axis values used by the font.

## Parameters

### `fontAxisValues` [out]

Type: **[DWRITE_FONT_AXIS_VALUE](https://learn.microsoft.com/windows/win32/api/dwrite_3/ns-dwrite_3-dwrite_font_axis_value)\***

A pointer to an array of **DWRITE_FONT_AXIS_VALUE** structures into which **GetFontAxisValues** writes the list of font axis values. You're responsible for managing the size and the lifetime of this array. Call [GetFontAxisValueCount](https://learn.microsoft.com/windows/win32/api/dwrite_3/nf-dwrite_3-idwritefontface5-getfontaxisvaluecount) to determine the size of array to allocate.

### `fontAxisValueCount`

Type: **[UINT32](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The maximum number of font axis values to write into the memory block pointed to by `fontAxisValues`.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the function succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes) [error code](https://learn.microsoft.com/windows/win32/com/com-error-codes-10).

|Return value|Description|
|-|-|
|E_INVALIDARG|`fontAxisValueCount` doesn't match the value returned by **GetFontAxisValueCount**.|

## Remarks

The values are returned in the canonical order defined by the font, clamped to the actual range supported. It's not necessarily the same axis value array that you passed to **CreateFontFace**.

## Examples

```cppwinrt
// main.cpp
#include <unknwn.h>
#include <winrt/base.h>
#include <dwrite_3.h>

int main()
{
	winrt::init_apartment();

	winrt::com_ptr<IDWriteFactory> factory;

	winrt::check_hresult(::DWriteCreateFactory(
		DWRITE_FACTORY_TYPE_SHARED,
		__uuidof(factory),
		reinterpret_cast<IUnknown**>(factory.put())));

	std::wstring filePath{ L"C:\\WINDOWS\\FONTS\\AGENCYB.TTF" };

	winrt::com_ptr<IDWriteFontFile> fontFile;

	factory->CreateFontFileReference(
		filePath.c_str(),
		nullptr,
		fontFile.put());

	std::array<IDWriteFontFile*, 1> fontFiles{ fontFile.get() };

	winrt::com_ptr<IDWriteFontFace> fontFace;

	winrt::check_hresult(factory->CreateFontFace(
		DWRITE_FONT_FACE_TYPE_TRUETYPE,
		1,
		fontFiles.data(),
		0,
		DWRITE_FONT_SIMULATIONS_NONE,
		fontFace.put()
	));

	winrt::com_ptr<IDWriteFontFace5> fontFace5{ fontFace.as<IDWriteFontFace5>() };
	
	UINT32 axisValueCount{ fontFace5->GetFontAxisValueCount() };

	DWRITE_FONT_AXIS_VALUE* axisValues{ new DWRITE_FONT_AXIS_VALUE[axisValueCount] };

	winrt::check_hresult(
		fontFace5->GetFontAxisValues(axisValues, axisValueCount));

	DWRITE_FONT_AXIS_VALUE* eachAxisValue{ axisValues };

	for (int ix = 0; ix < axisValueCount; ++ix, ++eachAxisValue)
	{
		printf("%zu,%f\n\r", eachAxisValue->axisTag, eachAxisValue->value);
	}

	delete[] axisValues;
}
```

## See also