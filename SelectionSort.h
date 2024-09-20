#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SelectionSort.generated.h"

/**
 * Estructura FSelectionSort
 */
USTRUCT(BlueprintType)
struct FSelectionSort
{
    GENERATED_BODY()

    FSelectionSort() : IntArray() {}

    UPROPERTY(BlueprintReadOnly)
    TArray<float> IntArray;  
};


UCLASS()
class PRUEBASCLASES_API UOrdenamientoSeleccion : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

private:


    static void SelectionSort(TArray<float>& Array);

public:


    // Función para ser llamada en Blueprints

    UFUNCTION(BlueprintCallable, Category = "Sorting")
    static TArray<float> Seleccion(const TArray<float>& InArray);
};
