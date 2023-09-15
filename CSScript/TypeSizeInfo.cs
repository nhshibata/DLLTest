using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSScript
{
    /// <summary>
    /// C++側からC#のサイズを取得するためのクラス
    /// </summary>
    class TypeSizeInfo
    {
        /// <summary>
        /// C++側からC#のサイズを取得するための関数
        /// </summary>
        /// <param name="typeName"></param>
        /// <returns></returns>
        public static int StringToSize(string typeName)
        {
            if (typeName == typeof(System.String).FullName)
            {
                return -1;
            }

            // 一致する型を自動で探す方法はない?
            // NOTE:ifが助長で直したい
            int ret = -1;

            ret = Generate<System.Int32>(typeName);
            if (ret != -1)return ret;

            ret = Generate<System.String>(typeName);
            if (ret != -1)return ret;

            ret = Generate<System.Single>(typeName);
            if (ret != -1)return ret;

            ret = Generate<System.Boolean>(typeName);
            if (ret != -1)return ret;

            return ret;
        }

        /// <summary>
        /// 型を受け取り、引き数として渡した型名と一致していれば型サイズを返す
        /// それ以外は-1とする
        /// </summary>
        /// <typeparam name="T"></typeparam>
        /// <param name="typeName"></param>
        /// <returns></returns>
        static int Generate<T>(string typeName)
        {
            if (typeName == typeof(T).FullName)
            {
                //return sizeof(type); 
                return System.Runtime.InteropServices.Marshal.SizeOf<T>();
            }
            return -1;
        }

    }
}
