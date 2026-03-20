#include "CvGameCoreDLL.h"
#include "CyCity.h"
#include "CyPlot.h"
#include "CyArea.h"
#include "CvInfos.h"

void CyCityPythonInterface1_Chunk1(python::class_<CyCity>& x);
void CyCityPythonInterface1_Chunk2(python::class_<CyCity>& x);
void CyCityPythonInterface1_Chunk3(python::class_<CyCity>& x);
void CyCityPythonInterface1_Chunk4(python::class_<CyCity>& x);
void CyCityPythonInterface1_Chunk5(python::class_<CyCity>& x);
void CyCityPythonInterface1_Chunk6(python::class_<CyCity>& x);

void CyCityPythonInterface1(python::class_<CyCity>& x)
{
    OutputDebugString("Python Extension Module - CyCityPythonInterface1\n");
    CyCityPythonInterface1_Chunk1(x);
    CyCityPythonInterface1_Chunk2(x);
    CyCityPythonInterface1_Chunk3(x);
    CyCityPythonInterface1_Chunk4(x);
    CyCityPythonInterface1_Chunk5(x);
    CyCityPythonInterface1_Chunk6(x);
}
