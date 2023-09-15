using System;
using System.Runtime.CompilerServices;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

/// <summary>
/// unsafe追加
/// プロパティ変更
/// </summary>
namespace CSScript
{
    unsafe public class Class1
    {
        unsafe int m_cnt = 123;
        unsafe string m_name = "first";

        unsafe public int Cnt { get => m_cnt; set => m_cnt = value; }
        unsafe public string Name { get => m_name; set => m_name = value; }

        void PrintMessage()
        {
            Console.WriteLine("Hello, Mono!");
        }

        // C++の関数(内部呼び出し)
        [MethodImpl(MethodImplOptions.InternalCall)]
        private extern static int Multiply(int a, int b);

        // C++の関数を呼び出す版
        void PrintMessage2()
        {
            // C++の関数を内部呼び出し
            Console.WriteLine("2 * 3 =" + Multiply(2, 3));
        }
    }
}
