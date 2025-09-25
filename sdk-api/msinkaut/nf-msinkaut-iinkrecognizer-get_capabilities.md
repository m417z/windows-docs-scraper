# IInkRecognizer::get_Capabilities

## Description

Gets the capabilities of the [IInkRecognizer](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkrecognizer) object.

This property is read-only.

## Parameters

## Remarks

A recognizer's capabilities are defined in the [InkRecognizerCapabilities](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkrecognizercapabilities) enumeration, and they include whether the recognizer supports character Autocomplete; whether it supports free, lined, or boxed input; and so on. For a complete list of recognizer capabilities, see the **InkRecognizerCapabilities** enumeration.

To determine if a recognizer has a particular capability, use a bitwise comparison operator to check for that capability.

For information about how to request various recognizer capabilities, or modes, see the [Guide](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognizercontext-get_guide) property of the [RecognizerContext](https://learn.microsoft.com/windows/desktop/tablet/inkrecognizercontext-class) object.

## See also

[Guide Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognizercontext-get_guide)

[IInkRecognizer Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkrecognizer)

[InkRecognizerCapabilities Enumeration](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkrecognizercapabilities)

[InkRecognizerContext Class](https://learn.microsoft.com/windows/desktop/tablet/inkrecognizercontext-class)