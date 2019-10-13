import java.io.*
import java.math.*
import java.security.*
import java.text.*
import java.util.*
import java.util.concurrent.*
import java.util.function.*
import java.util.regex.*
import java.util.stream.*
import kotlin.collections.*
import kotlin.comparisons.*
import kotlin.io.*
import kotlin.jvm.*
import kotlin.jvm.functions.*
import kotlin.jvm.internal.*
import kotlin.ranges.*
import kotlin.sequences.*
import kotlin.text.*
import java.util.ArrayList



class Main {
    companion object{
        fun superReducedString(s: String): String {

            fun getStringRepresentation(list: ArrayList<Char>): String {
                val builder = StringBuilder(list.size)
                for (ch in list) {
                    builder.append(ch)
                }
                return builder.toString()
            }

            val stack = Stack<Char>()

            s.forEach { it ->
                if (stack.isEmpty())
                    stack.push(it)
                else
                    if (stack.peek() == it)
                        stack.pop()
                    else
                        stack.push(it)
            }

            if (stack.isEmpty()){
                return "Empty String";
            }

            val res = ArrayList(stack)

            return getStringRepresentation(res)
        }

        @JvmStatic fun main(args: Array<String>) {
            val s = readLine()!!

            val result = superReducedString(s)

            println(result)
        }
    }
}
