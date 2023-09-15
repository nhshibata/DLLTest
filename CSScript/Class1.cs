using System;
using System.Runtime.CompilerServices;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSScript
{
    public class Class1
    {
        int m_cnt = 0;
        string m_name = "first";

        public int Cnt { get => m_cnt; set => m_cnt = value; }
        public string Name { get => m_name; set => m_name = value; }

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
